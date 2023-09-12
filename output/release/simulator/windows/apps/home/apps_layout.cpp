// This file is auto-generated by apps_layout.py

#include "apps_layout.h"
#include <apps/country_preferences.h>
#include <apps/global_preferences.h>
#include <assert.h>

namespace Home {

/* Permutations are built so that Permutation[n] is the index of the snapshot
 * for the nth app in the Home menu. */

static constexpr int DefaultAppsPermutation[] = {
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  11,
  12,
  0,
};
static_assert(DefaultAppsPermutation[0] == 0, "The Home apps must always be at index 0");

static constexpr int HidePythonAppsPermutation[] = {
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  11,
  12,
  0,
};
static_assert(HidePythonAppsPermutation[0] == 0, "The Home apps must always be at index 0");

int PermutedAppSnapshotIndex(int index) {
  CountryPreferences::HomeAppsLayout currentLayout = GlobalPreferences::sharedGlobalPreferences()->homeAppsLayout();
  if (currentLayout == CountryPreferences::HomeAppsLayout::Default) {
    return DefaultAppsPermutation[index];  }
  if (currentLayout == CountryPreferences::HomeAppsLayout::HidePython) {
    return HidePythonAppsPermutation[index];  }
  assert(false);
  return -1;
}

}
